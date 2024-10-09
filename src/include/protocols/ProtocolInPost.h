 /**
 *  ProtocolInPost.h
 *
 *  Bridge to work with  a request.
 *  For http method POST
 *
 *  If the request http method is the POST 
 *  and you just need to get data such as key or key-value pair, use this class
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/rocksserver
 */


namespace RocksServer {

    class ProtocolInPost
    {
    public:
        ProtocolInPost(const EvRequest &r) :
            request(r),
            raw(request.getPostData()),
            uri(r.getUri()),
            pathlen(uri.find('?'))
        {}

        // Check query
        bool check(const ProtocolOut &out) const
        {
            // Detect if current method is POST
            if(!request.isPost()) {
                EvLogger::writeLog("Request method should be POST");
                out.fail();
                return false;
            }

            // Check if POST data is empty
            if(!raw.size()) {
                EvLogger::writeLog("Request POST data is empty");
                out.fail();
                return false;
            }

            return (uri.size()-1 > pathlen);
        }

        // retrive key
        rocksdb::Slice key() const
        {
            return rocksdb::Slice(uri.data() + pathlen + 1, uri.size() - pathlen - 1);
        }

        // retrive key and value
        std::pair<rocksdb::Slice, rocksdb::Slice> pair() const
        {
            return std::make_pair(key(), rocksdb::Slice(raw, raw.size()));
        }

    protected:
        const EvRequest &request;
        const PostData raw;
        const std::string uri;
        // length of "/path"
        const std::string::size_type pathlen;
    };

}
