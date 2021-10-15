# avaliacacao-cpp

This project was developed in Linux and uses CMake, Conan, Boost and Gooogle Test.

## install dependencies
```
sudo apt update
sudo apt-get install build-essential cmake python3 python3-pip -y
sudo pip3 install conan
```

## build 
```
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles"
cmake --build .
```


## troubleshooting

Recently conan update its remote servers and maybe its necessary add it.

```
conan remote add -i 0 conancenter https://center.conan.io
```
