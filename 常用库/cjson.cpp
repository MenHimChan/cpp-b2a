#include <cjson/cJSON.h>
#include <iostream>
#include <string>

using namespace std;

// 生成示例 JSON（返回紧凑字符串），同时打印格式化和紧凑两种形式
string create_json_compact() {
    cout << "=== create_json_compact ===" << endl;
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "John");
    cJSON_AddNumberToObject(root, "age", 30);

    cJSON *address = cJSON_AddObjectToObject(root, "address");
    cJSON_AddStringToObject(address, "city", "Beijing");
    cJSON_AddStringToObject(address, "country", "China");

    cJSON *contact = cJSON_AddObjectToObject(root, "contact");
    cJSON_AddStringToObject(contact, "email", "john@example.com");
    cJSON_AddStringToObject(contact, "phone", "123456789");

    // 打印：可读（带缩进）
    char *pretty = cJSON_Print(root);
    if (pretty) {
        cout << pretty << endl;                 // 有缩进版本
        free(pretty);
    }

    // 返回紧凑字符串（用于解析/网络）
    char *compact = cJSON_PrintUnformatted(root);
    string result;
    if (compact) {
        cout << compact << endl;
        result.assign(compact);                 // 保存紧凑版本
        free(compact);
    }

    cJSON_Delete(root);
    cout << "=== create_json_compact ===" << endl;
    return result;
}

// 测试1：基本解析与字段读取（string/number）
void test_parse_basic(const string &json) {
    cJSON *root = cJSON_Parse(json.c_str());            // 将字符串转化成CJson能操作的对象

    // 读取字符串字段 name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name");           // 拿到name字段指针
    if (cJSON_IsString(name) && name->valuestring) {                        // 判断name字段的值是string && 不为null
        cout << "[test_parse_basic] name: " << cJSON_GetStringValue(name) << endl;
        cout << name->valuestring << endl;                                  // John
    }

    // 读取数字字段 age 
    cJSON *age = cJSON_GetObjectItemCaseSensitive(root, "age");             // 拿到age字段指针
    if (cJSON_IsNumber(age)) {                                              // 判断age字段的值是number
        cout << "[test_parse_basic] age: " << age->valuedouble << endl;
    }

    cJSON_Delete(root);
}

// 测试2：访问嵌套对象（object 内的字段）
void test_access_nested(const string &json) {
    cJSON *root = cJSON_Parse(json.c_str());
    if (!root) return;

    cJSON *addr = cJSON_GetObjectItemCaseSensitive(root, "address");
    if (cJSON_IsObject(addr)) {
        cJSON *city = cJSON_GetObjectItemCaseSensitive(addr, "city");
        if (cJSON_IsString(city)) cout << "[test_access_nested] city: " << cJSON_GetStringValue(city) << endl;
    }

    cJSON *contact = cJSON_GetObjectItemCaseSensitive(root, "contact");
    if (cJSON_IsObject(contact)) {
        cJSON *phone = cJSON_GetObjectItemCaseSensitive(contact, "phone");
        if (cJSON_IsString(phone)) cout << "[test_access_nested] phone: " << cJSON_GetStringValue(phone) << endl;
    }

    cJSON_Delete(root);
}

// 测试3：数组遍历示例
void test_array_iteration() {
    const char *json = R"({"tags":["red","green","blue"]})";
    cJSON *root = cJSON_Parse(json);
    if (!root) return;

    cJSON *tags = cJSON_GetObjectItemCaseSensitive(root, "tags");
    if (cJSON_IsArray(tags)) {
        cJSON *elem = nullptr;
        printf("[test_array_iteration] tags:\n");
        cJSON_ArrayForEach(elem, tags) {
            if (cJSON_IsString(elem) && elem->valuestring) {
                printf("  - %s\n", cJSON_GetStringValue(elem));
            }
        }
    }

    cJSON_Delete(root);
}

// 测试4：解析错误处理示例
void test_error_handling() {
    const char *bad = "{ \"name\": "; // 非法 JSON
    cJSON *root = cJSON_Parse(bad);
    if (!root) {
        const char *err = cJSON_GetErrorPtr();
        cout << "[test_error_handling] parse failed at: " << (err ? err : "unknown") << endl;
    } else {
        cJSON_Delete(root);
    }
}

int main() {
    // 生成示例 JSON 并获取紧凑字符串
    string json = create_json_compact();

    // cout << json << endl; // {"name":"John","age":30,"address":{"city":"Beijing","country":"China"},"contact":{"email":"john@example.com","phone":"123456789"}}

    // 运行各个解析测试
    test_parse_basic(json);
    // test_access_nested(json);
    // test_array_iteration();
    // test_error_handling();

    return 0;
}

