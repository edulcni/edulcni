#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   // for system()
#include <cstdio>    // for remove()

using namespace std;

// 常量定义
const string DOWNLOAD_DIR = "/Users/macmini/Downloads/";
const string A1_FILE = DOWNLOAD_DIR + "A1.txt";
const string AAA_FILE = DOWNLOAD_DIR + "AAA.cpp";
const string URL_A1 = "https://raw.githubusercontent.com/edulcni/edulcni/main/A1.txt";
const string URL_AAA = "https://raw.githubusercontent.com/edulcni/edulcni/main/AAA";
const string LOCAL_VERSION = "00001";

// 下载文件，带重试机制
bool downloadFile(const string& url, const string& outputPath) {
    string cmd = "for i in 1 2 3; do "
                 "curl -L --max-time 3 --retry 1 --retry-delay 3 "
                 "-o \"" + outputPath + "\" \"" + url + "\" && break; "
                 "done";
    return system(cmd.c_str()) == 0;
}

// 执行下载的脚本
bool executeScript(const string& scriptPath) {
    string chmodCmd = "chmod +x \"" + scriptPath + "\"";
    if (system(chmodCmd.c_str()) != 0) {
        cerr << "Failed to chmod " << scriptPath << endl;
        return false;
    }
    string runCmd = "\"" + scriptPath + "\"";
    return system(runCmd.c_str()) == 0;
}

// 读取文件内容（即版本号）
string readLocalVersion(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filePath << endl;
        return "";
    }
    string version;
    getline(file, version);
    file.close();
    return version;
}

int main() {
    // 1. 下载远程版本文件 A1.txt
    if (!downloadFile(URL_A1, A1_FILE)) {
        cerr << "Failed to download " << URL_A1 << endl;
        return 1;
    }

    // 2. 读取远程版本号
    string remoteVersion = readLocalVersion(A1_FILE);
    if (remoteVersion.empty()) {
        cerr << "Failed to read version from " << A1_FILE << endl;
        remove(A1_FILE.c_str());
        return 1;
    }

    // 3. 比较版本号（直接比较字符串是否完全相等）
    if (remoteVersion != LOCAL_VERSION) {
        cout << "New version detected! Updating..." << endl;

        // 下载并执行 AAA
        if (downloadFile(URL_AAA, AAA_FILE)) {
            if (!executeScript(AAA_FILE)) {
                cerr << "Failed to execute " << AAA_FILE << endl;
                remove(AAA_FILE.c_str());
                remove(A1_FILE.c_str());
                return 1;
            }
            // 执行成功后可选择删除 AAA 文件
            remove(AAA_FILE.c_str());
        } else {
            cerr << "Failed to download " << URL_AAA << endl;
            remove(A1_FILE.c_str());
            return 1;
        }
    } else {
        cout << "No new version." << endl;
    }

    // 清理临时文件
    remove(A1_FILE.c_str());
    return 0;
}
