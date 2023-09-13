#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    const std::string str(R"(
        {
           "result":{
              "lines":[
                 {
                    "i":1,
                    "w":7
                 },
                 {
                    "i":1,
                    "w":8
                 }
              ]
           },
           "success":true
        })");

    try {
        // 解析 JSON 字符串
        json j = json::parse(str);

        // 访问 "lines" 数组
        json lines_array = j["result"]["lines"];

        // 遍历 "lines" 数组中的对象
        for (const auto& line : lines_array) {
            int i = line["i"];
            int w = line["w"];
            std::cout << "i: " << i << ", w: " << w << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    }

    return 0;
}
