PATH="${PATH}:."
PS1='\$ '
CXXFLAGS="-std=c++14 -pedantic -Wall -I .."
export CXXFLAGS
function clean {
    find $1/ch* \( -type f -executable \) -o \( -name '*.o' \) -delete
}
