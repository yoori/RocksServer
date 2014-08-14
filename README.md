This is a simple server for RocksDB.

Supports the following operations:

**Get**

Get value by key

**Multi get**

Get values by keys

**Set**

Set value by key

**Multi set**

Set values by keys

**Delete key**

Delete key from DB

**Multi delete keys**

Delete keys from DB

**Check key exist**

Check key existing

**Imcrement**

Imcrement value by key


For more details see: [protocol description](protocol.md)

##Dependency
[RocksDB](https://github.com/facebook/rocksdb/)
[LibEvent](http://libevent.org/)
The recommended compiler: `clang`
the compiler must support `C++11`

## Run
First install libevend and compile or install RocksDB.
After run command 
```
make
```

After compiling run `./RocksServer.bin`

## Usage
Exemple of usage: [driver for PHP](drivers/php/README.md)
Or any your implementation by [protocol description](protocol.md)

## Note
Currently under development.

The RocksServer is workable but it needs many improvements.
It has not yet been used in production, but I have plans to run it on a production server.

Sorry for my english.

## License
BSD

