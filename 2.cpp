#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// 定义 C++ 结构体来表示 JSON 数据的结构
struct Line {
    int i;
    int w;
};

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

        // 获取 "lines" 数组
        json lines_array = j["result"]["lines"];

        // 遍历 "lines" 数组中的对象
        std::vector<Line> lines;
        for (const auto& line : lines_array) {
            // 添加条件：只添加满足条件的对象（例如，w 大于等于 8）
            if (line["w"] >= 8) {
                Line line_obj;
                line_obj.i = line["i"];
                line_obj.w = line["w"];
                lines.push_back(line_obj);
            }
        }

        // 打印满足条件的 C++ 对象
        for (const auto& line : lines) {
            std::cout << "i: " << line.i << ", w: " << line.w << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    }

    return 0;
}
