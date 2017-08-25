#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main()
{
    //创建mongo实例
    mongocxx::instance instance{};
    //建立连接
    mongocxx::client client{mongocxx::uri{}};
    //从客户端上获取数据库
    mongocxx::database db = client["mydb"];
    //从数据库db获取test集合
    mongocxx::collection coll = db["test"];
    //创建文档构建器
    auto builder = bsoncxx::builder::stream::document{};
    //创建文档
    bsoncxx::document::value doc_value = builder<<"name"<<"MongoDB"<<"type"<<"database"<<"count"<<1<<"versions"<<bsoncxx::builder::stream::open_array<<"v3.2"<<"v3.0"<<"v2.6"
    <<close_array
    <<"info"<<bsoncxx::builder::stream::open_document
    <<"x"<<203<<"y"<<102<<bsoncxx::builder::stream::close_document
    <<bsoncxx::builder::stream::finalize;
    //文档创建好之后不能直接使用，需要转换成view
    bsoncxx::document::view view = doc_value.view();

    //查询单条文档
    //bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result=coll.find_one(builder<<"age"<<18<<finalize);
    //std::cout<<bsoncxx::to_json(*maybe_result)<<std::endl;
    mongocxx::cursor cursor = coll.find(builder<<finalize);
    for(auto && c:cursor)
    {
        std::cout<<bsoncxx::to_json(c)<<std::endl;
    }
    return 0;
}
