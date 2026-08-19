if [ -d "builds" ]; then
    rm -rf builds
fi

mkdir -p build && cd build
cmake ..
make