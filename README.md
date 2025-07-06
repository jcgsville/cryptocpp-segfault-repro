# cryptocpp-segfault-repro

I believe the `CRYPTOPP_DISABLE_ASM` flag causes a segfault in `CryptoPP::HMAC<CryptoPP::SHA256>`'s `Update()`.

I started up a fresh t2.micro EC2 instance with the following AMI: `ubuntu/images/hvm-ssd-gp3/ubuntu-noble-24.04-amd64-server-20250610`

```sh
sudo apt-get update
sudo apt-get install cmake build-essential

mkdir ~/app
cd ~/app
git clone https://github.com/jcgsville/cryptocpp-segfault-repro.git
cd cryptocpp-segfault-repro
git submodule update --init --recursive

cmake -B .build -DCMAKE_BUILD_TYPE=Release && cmake --build .build && cmake --build .build && .build/repro
```

rm -rf .build && cmake -B .build -DCMAKE_BUILD_TYPE=Release && cmake --build .build && cmake --build .build && .build/repro