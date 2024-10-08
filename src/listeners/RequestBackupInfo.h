/**
 *  RequestBackupInfo.h
 *
 *  Request listener for command "/backup/info"
 *  Show information about backups
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/rocksserver
 */

#pragma once

namespace RocksServer {

    class RequestBackupInfo : public RequestBase<ProtocolInTrivial, ProtocolOut>
    {
    public:
        
        RequestBackupInfo(const rocksdb::BackupEngineOptions &bkOptions) noexcept :
            bkOptions(bkOptions)
        {}

        /**
         *  Runs request listener
         *  @param       protocol in object
         *  @param       protocol out object
         */
        virtual void run(const ProtocolInTrivial &in, const ProtocolOut &out) noexcept final;

        virtual ~RequestBackupInfo() = default;
    private:
        const rocksdb::BackupEngineOptions &bkOptions;
    };
}
