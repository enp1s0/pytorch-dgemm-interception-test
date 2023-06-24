# DGEMM interception test

## Build
```bash
git clone https://github.com/enp1s0/pytorch-dgemm-interception-test
cd pytorch-dgemm-interception-test
make
```

## test
```bash
export LD_PRELOAD=$(realpath ./libdgemm_intercept.so)
python test/main.py
# Result: DGEMM(400, 300, 400) is called
```

## License
CC0, Public domain
