#CC 	 = clang++
CC 	 = g++

NAME	 = RocksServer

OPT_FLAGS=-O4
# OPT_FLAGS=-g -O0

#compiler flags
CFLAGS	 = -std=c++17 $(OPT_FLAGS) -pedantic -Wall -Wextra -Wno-unused-parameter -fno-rtti -fno-exceptions -flto=auto
LINK_FLAGS = -static


BINFILE  = bin/$(NAME).bin

# path to RocksDB source
ROCKSPATH	 = /usr

# ROCKSLIB = -lrocksdb -lpthread -lrt -lsnappy -lgflags -lz -lbz2 -lzstd -lbz2 -llz4
ROCKSLIB = -lrocksdb -lpthread -lsnappy -lz -lzstd -lbz2 -llz4 -ldl


# path to Libevent source
LEVENTPATH	 = $(PWD)/../deps/libevent

LEVENTI	 = 
LEVENTL	 = $(LEVENTPATH)/.libs

INCLUDES   = -I. -I"$(ROCKSPATH)/include" \
             -I"$(LEVENTPATH)/include"

LIBRARIES  = -L"$(ROCKSPATH)/lib"

CP = cp -f
CPR = cp -fR
#CPR = ln -sf
#CP = ln -sf
SRC=`pwd`

VERSION=$(shell git -C "." describe --tags --candidates=1)

all: ${BINFILE}


RocksServer.h.gch: RocksServer.h
	g++ $(CFLAGS) $(INCLUDES) -c RocksServer.h -o RocksServer.h.gch

bin/obj/$(NAME).rs.o: $(NAME).cpp
	$(CC) $(NAME).cpp $(CFLAGS) -DROCKSSERVER_VERSION="\"$(VERSION)\"" $(INCLUDES) -c -o bin/obj/$(NAME).rs.o

bin/obj/EvLogger.rs.o: evhttp/EvLogger.cpp
	$(CC) evhttp/EvLogger.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/EvLogger.rs.o

bin/obj/EvServer.rs.o: evhttp/EvServer.cpp
	$(CC) evhttp/EvServer.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/EvServer.rs.o

bin/obj/EvResponse.rs.o: evhttp/EvResponse.cpp
	$(CC) evhttp/EvResponse.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/EvResponse.rs.o

bin/obj/EvRequest.rs.o: evhttp/EvRequest.cpp
	$(CC) evhttp/EvRequest.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/EvRequest.rs.o

bin/obj/RocksDBWrapper.rs.o: rocks/RocksDBWrapper.cpp
	$(CC) rocks/RocksDBWrapper.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RocksDBWrapper.rs.o

bin/obj/ProtocolInGetIterator.rs.o: rocks/ProtocolInGetIterator.cpp
	$(CC) rocks/ProtocolInGetIterator.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/ProtocolInGetIterator.rs.o

bin/obj/ProtocolInPostKeysIterator.rs.o: rocks/ProtocolInPostKeysIterator.cpp
	$(CC) rocks/ProtocolInPostKeysIterator.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/ProtocolInPostKeysIterator.rs.o

bin/obj/ProtocolInPostPairsIterator.rs.o: rocks/ProtocolInPostPairsIterator.cpp
	$(CC) rocks/ProtocolInPostPairsIterator.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/ProtocolInPostPairsIterator.rs.o

bin/obj/Extend.rs.o: extend/Extend.cpp
	$(CC) extend/Extend.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/Extend.rs.o

bin/obj/PlugContainer.rs.o: extend/PlugContainer.cpp
	$(CC) extend/PlugContainer.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/PlugContainer.rs.o

bin/obj/Extension.rs.o: extend/Extension.cpp
	$(CC) extend/Extension.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/Extension.rs.o

bin/obj/IniConfigs.rs.o: iniparse/IniConfigs.cpp
	$(CC) iniparse/IniConfigs.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/IniConfigs.rs.o

bin/obj/IniValue.rs.o: iniparse/IniValue.cpp
	$(CC) iniparse/IniValue.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/IniValue.rs.o

bin/obj/restore.o: utils/restore.cpp
	$(CC) utils/restore.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/restore.o

bin/obj/restore_hr.o: utils/restore_hr.cpp
	$(CC) utils/restore_hr.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/restore_hr.o

bin/obj/human_readable.o: utils/human_readable.cpp
	$(CC) utils/human_readable.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/human_readable.o

bin/obj/human_readable_batches.o: utils/human_readable_batches.cpp
	$(CC) utils/human_readable_batches.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/human_readable_batches.o

bin/obj/rows_number.o: utils/rows_number.cpp
	$(CC) utils/rows_number.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/rows_number.o

# Main requests
bin/obj/RequestKeyExist.rs.o: listeners/RequestKeyExist.cpp
	$(CC) listeners/RequestKeyExist.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestKeyExist.rs.o

bin/obj/RequestGet.rs.o: listeners/RequestGet.cpp
	$(CC) listeners/RequestGet.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestGet.rs.o

bin/obj/RequestMget.rs.o: listeners/RequestMget.cpp
	$(CC) listeners/RequestMget.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestMget.rs.o

bin/obj/RequestIncr.rs.o: listeners/RequestIncr.cpp
	$(CC) listeners/RequestIncr.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestIncr.rs.o

bin/obj/RequestPrefIt.rs.o: listeners/RequestPrefIt.cpp
	$(CC) listeners/RequestPrefIt.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestPrefIt.rs.o

bin/obj/RequestSeekPrev.rs.o: listeners/RequestSeekPrev.cpp
	$(CC) listeners/RequestSeekPrev.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestSeekPrev.rs.o

bin/obj/RequestSeekNext.rs.o: listeners/RequestSeekNext.cpp
	$(CC) listeners/RequestSeekNext.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestSeekNext.rs.o

bin/obj/RequestSeekPrevRange.rs.o: listeners/RequestSeekPrevRange.cpp
	$(CC) listeners/RequestSeekPrevRange.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestSeekPrevRange.rs.o

bin/obj/RequestSeekNextRange.rs.o: listeners/RequestSeekNextRange.cpp
	$(CC) listeners/RequestSeekNextRange.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestSeekNextRange.rs.o

bin/obj/RequestTailing.rs.o: listeners/RequestTailing.cpp
	$(CC) listeners/RequestTailing.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestTailing.rs.o

bin/obj/RequestSet.rs.o: listeners/RequestSet.cpp
	$(CC) listeners/RequestSet.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestSet.rs.o

bin/obj/RequestMset.rs.o: listeners/RequestMset.cpp
	$(CC) listeners/RequestMset.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestMset.rs.o

bin/obj/RequestDel.rs.o: listeners/RequestDel.cpp
	$(CC) listeners/RequestDel.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestDel.rs.o

bin/obj/RequestMdel.rs.o: listeners/RequestMdel.cpp
	$(CC) listeners/RequestMdel.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestMdel.rs.o

bin/obj/RequestMdelset.rs.o: listeners/RequestMdelset.cpp
	$(CC) listeners/RequestMdelset.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestMdelset.rs.o

bin/obj/RequestStats.rs.o: listeners/RequestStats.cpp
	$(CC) listeners/RequestStats.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestStats.rs.o

bin/obj/RequestBackup.rs.o: listeners/RequestBackup.cpp
	$(CC) listeners/RequestBackup.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestBackup.rs.o

bin/obj/RequestBackupDel.rs.o: listeners/RequestBackupDel.cpp
	$(CC) listeners/RequestBackupDel.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestBackupDel.rs.o

bin/obj/RequestBackupMdel.rs.o: listeners/RequestBackupMdel.cpp
	$(CC) listeners/RequestBackupMdel.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestBackupMdel.rs.o

bin/obj/RequestBackupInfo.rs.o: listeners/RequestBackupInfo.cpp
	$(CC) listeners/RequestBackupInfo.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/RequestBackupInfo.rs.o

bin/obj/change_owner.rs.o: misc/change_owner.cpp
	$(CC) misc/change_owner.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/change_owner.rs.o

bin/obj/change_files_limit.rs.o: misc/change_files_limit.cpp
	$(CC) misc/change_files_limit.cpp $(CFLAGS) $(INCLUDES) -c -o bin/obj/change_files_limit.rs.o

bin/obj/version.rs.o: misc/version.cpp
	$(CC) misc/version.cpp $(CFLAGS) -DROCKSSERVER_VERSION="\"$(VERSION)\"" $(INCLUDES) -c -o bin/obj/version.rs.o


.PHONY: obj
obj: RocksServer.h.gch bin/obj/$(NAME).rs.o bin/obj/EvLogger.rs.o bin/obj/EvServer.rs.o \
bin/obj/EvResponse.rs.o bin/obj/EvRequest.rs.o bin/obj/RocksDBWrapper.rs.o \
bin/obj/ProtocolInGetIterator.rs.o bin/obj/ProtocolInPostKeysIterator.rs.o bin/obj/ProtocolInPostPairsIterator.rs.o \
bin/obj/Extend.rs.o \
bin/obj/PlugContainer.rs.o bin/obj/Extension.rs.o bin/obj/IniConfigs.rs.o bin/obj/IniValue.rs.o \
bin/obj/RequestKeyExist.rs.o \
bin/obj/RequestGet.rs.o bin/obj/RequestMget.rs.o bin/obj/RequestIncr.rs.o \
bin/obj/RequestPrefIt.rs.o bin/obj/RequestTailing.rs.o \
bin/obj/RequestSeekPrev.rs.o bin/obj/RequestSeekNext.rs.o \
bin/obj/RequestSeekPrevRange.rs.o bin/obj/RequestSeekNextRange.rs.o \
bin/obj/RequestSet.rs.o bin/obj/RequestMset.rs.o \
bin/obj/RequestDel.rs.o bin/obj/RequestMdel.rs.o bin/obj/RequestMdelset.rs.o \
bin/obj/RequestStats.rs.o bin/obj/RequestBackup.rs.o bin/obj/RequestBackupInfo.rs.o \
bin/obj/RequestBackupDel.rs.o bin/obj/RequestBackupMdel.rs.o bin/obj/change_owner.rs.o \
bin/obj/change_files_limit.rs.o bin/obj/version.rs.o


bin/restore.bin: bin/obj/restore.o
	$(CC) bin/obj/restore.o $(CFLAGS) $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o bin/restore.bin
	strip --strip-all bin/restore.bin

bin/restore_hr.bin: bin/obj/restore_hr.o
	$(CC) bin/obj/restore_hr.o $(CFLAGS) $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o bin/restore_hr.bin
	strip --strip-all bin/restore_hr.bin

bin/human_readable.bin: bin/obj/human_readable.o
	$(CC) bin/obj/human_readable.o $(CFLAGS) $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o bin/human_readable.bin
	strip --strip-all bin/human_readable.bin

bin/human_readable_batches.bin: bin/obj/human_readable_batches.o
	$(CC) bin/obj/human_readable_batches.o $(CFLAGS) $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o bin/human_readable_batches.bin
	strip --strip-all bin/human_readable_batches.bin

bin/rows_number.bin: bin/obj/rows_number.o
	$(CC) bin/obj/rows_number.o $(CFLAGS) $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o bin/rows_number.bin


#dynamic:
${BINFILE}: obj bin/restore.bin bin/restore_hr.bin bin/human_readable.bin bin/human_readable_batches.bin bin/rows_number.bin
	$(CC) bin/obj/*.rs.o $(CFLAGS) -levent -ldl $(LIBRARIES) -L$(LEVENTL) $(ROCKSLIB) $(LINK_FLAGS) -o ${BINFILE}
	strip --strip-all ${BINFILE}
	@echo
	@echo "\033[1;36mBuild complite \033[0m"
#	@echo "To start the server run ./bin/$(NAME).bin config.ini"


.PHONY: static
static: obj bin/restore.bin bin/restore_hr.bin bin/human_readable.bin bin/human_readable_batches.bin bin/rows_number.bin
	$(CC) bin/obj/*.rs.o $(CFLAGS) $(LEVENTL)/libevent.a -ldl $(LIBRARIES) $(ROCKSLIB) $(LINK_FLAGS) -o ${BINFILE}
	strip --strip-all ${BINFILE}
	@echo
	@echo "\033[1;34mBuild complite \033[0m"


.PHONY: clean install uninstall uninstall-clean


clean:
	rm -f bin/obj/*.o bin/*.bin RocksServer.h.gch

gch:
	g++ $(CFLAGS) $(INCLUDES) -c RocksServer.h -o RocksServer.h.gch


install:
	mkdir -p /var/rocksserver
	chown nobody /var/rocksserver
	$(CP) ${SRC}/bin/RocksServer.bin /usr/local/bin/rocksserver
	$(CP) ${SRC}/bin/restore.bin /usr/local/bin/rocksrestore
	$(CP) ${SRC}/bin/restore_hr.bin /usr/local/bin/rocksrestore_hr
	$(CP) ${SRC}/bin/human_readable.bin /usr/local/bin/rocks_human_readable
	$(CP) ${SRC}/bin/human_readable_batches.bin /usr/local/bin/rocks_human_readable_batches
	$(CP) ${SRC}/bin/rows_number.bin /usr/local/bin/rocks_rows_number
	$(CP) -L ${SRC}/../init.d/rocksserver /etc/init.d/rocksserver
	mkdir -p /etc/rocksserver
	$(CP) ${SRC}/config.ini /etc/rocksserver/config.ini
	mkdir -p /usr/lib/rocksserver/plugins
	#
	mkdir -p /usr/include/rocksserver
	$(CPR) ${SRC}/include/* /usr/include/rocksserver/
	#
	mkdir -p /usr/include/rocksserver/rocksdb
	$(CPR) ${SRC}/../deps/rocksdb/include/* /usr/include/rocksserver/rocksdb/
	#
	update-rc.d rocksserver defaults

uninstall:
	update-rc.d -f rocksserver remove
	rm -f /usr/local/bin/rocksrestore
	rm -f /usr/local/bin/rocksrestore_hr
	rm -f /usr/local/bin/rocksserver
	rm -f /usr/local/bin/rocks_human_readable
	rm -f /usr/local/bin/rocks_human_readable_batches
	rm -f /usr/local/bin/rocks_rows_number
	rm -f /etc/init.d/rocksserver

uninstall-clean:
	update-rc.d -f rocksserver remove
	rm -fR /var/rocksserver
	rm -fR /etc/rocksserver
	rm -fR /usr/lib/rocksserver/plugins
	rm -fR /usr/include/rocksserver
	rm -f /usr/local/bin/rocksrestore
	rm -f /usr/local/bin/rocksrestore_hr
	rm -f /usr/local/bin/rocks_human_readable
	rm -f /usr/local/bin/rocks_human_readable_batches
	rm -f /usr/local/bin/rocks_rows_number
	rm -f /etc/init.d/rocksserver


