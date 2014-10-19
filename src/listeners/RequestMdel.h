/**
 *  RequestMdel.h
 *
 *  Request listener for command "mset" (multiset)
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/rocksserver
 */


namespace RocksServer {

    class RequestMdel : public RequestBase
    {
    public:
        RequestMdel(RocksDBWrapper &rdb) : _rdb(rdb) {}

        /**
         *  Runs request listener
         *  @param       event request object
         *  @param       protocol object
         */
        virtual void run(const EvRequest &request, const Protocol &prot) override
        {
            // Detect if current method is POST
            if( !request.isPost() ) {
                

                //buf.add("Request method should be POST");
                prot.fail();


                return;
            }
            
            auto raw = request.getPostData();

            if(!raw.size()) {
                //buf.add("FAIL", 4);
                prot.fail();
                return;
            }

            // create a RocksDB delete batch
            rocksdb::WriteBatch batch;

            std::string::size_type lpos = 0;
            std::string::size_type rpos = raw.find('\n');
            std::string::size_type len  = raw.size();

            // filling batch
            while(rpos < std::string::npos) {
                batch.Delete(rocksdb::Slice(raw+lpos, rpos-lpos));
                lpos = rpos+1;
                rpos = raw.find('\n', lpos);
            }
            batch.Delete(rocksdb::Slice(raw+lpos, len-lpos));

            if(_rdb.mset(batch)) {
                //buf.add("OK", 2);
                prot.ok();
            } else {
                //buf.add("FAIL", 4);
                prot.fail();
            }
        }

        virtual ~RequestMdel() {}
    private:
        RocksDBWrapper& _rdb;
    };

}
