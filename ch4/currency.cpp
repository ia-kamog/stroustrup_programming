// Convert yen, euros, pounds into dollars
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <regex>
#include <utility>
#include <curl/curl.h>

const std::string ecb_url =
     "http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml";

static std::map<std::string, double> get_currency_conversions();
static std::size_t write_data(void *, std::size_t, std::size_t, void *);
static std::string http_get(const std::string& url);
static std::string get_ecb_xml();
int main()
{
     curl_global_init(CURL_GLOBAL_ALL);
     auto conversions = get_currency_conversions();
     double value;
     std::string unit;
     while (std::cin >> value >> unit) {
	  double factor;
	  if (unit == "yen")
	       factor = conversions["JPY"];
	  else if (unit == "euro")
	       factor = conversions["EUR"];
	  else if (unit == "pound")
	       factor = conversions["GBP"];
	  else {
	       std::cout << "Unknown unit: " << unit << '\n';
	       continue;
	  }
	  std::cout << value << ' ' << unit << " = " << factor*value << '\n';
     }
     curl_global_cleanup();
}

static std::size_t
write_data(void *buf, std::size_t size, std::size_t nmemb, void *out)
{
     std::string *sp = reinterpret_cast<std::string *>(out);
     char *b = reinterpret_cast<char *>(buf);
     const std::size_t bytes = size*nmemb;
     for (std::size_t i = 0; i < bytes; i++)
	  sp->push_back(b[i]);
}

static std::string
http_get(const std::string& url)
{
     auto curl = curl_easy_init();
     if (!curl)
	  throw std::runtime_error("curl initiation failure");
     std::string out = "";
     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &out);
     CURLcode code = curl_easy_perform(curl);
     curl_easy_cleanup(curl);
     if (code != CURLE_OK)
	  throw std::runtime_error("curl can't get " + url);
     return out;
}

static std::string get_ecb_xml()
{
     return http_get(ecb_url);
}

static std::map<std::string, double>
get_currency_conversions()
{
     std::map<std::string, double> result;
     result["EUR"] = 1.0;
     std::string xml = get_ecb_xml();
     std::regex reg("\\s*<Cube currency='([A-Z]+)'\\s+rate='([0-9.]+)'\\s*/>");
     auto start = std::sregex_iterator(xml.begin(), xml.end(), reg);
     auto end = std::sregex_iterator();
     for (auto i = start; i != end; ++i) {
	  std::smatch m = *i;
	  if (m.size() != 3)
	       continue;
	  std::string curr = (*i)[1];
	  double conv = std::stod((*i)[2]);
	  result[curr] = conv;
     }
     double usd_eur = result["USD"];
     for (auto& v: result)
	  v.second /= usd_eur;
     return result;
}
