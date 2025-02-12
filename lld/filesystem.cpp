#include <bits/stdc++.h>


// Implement a in memory file system 
// # Initialize the file system
// fs = FileSystem()

// # Create directories
// fs.mkdir("/a/b")
// fs.mkdir("/a/c")

// # Add files
// fs.add_file("/a/b/file1.txt", "Hello, World!")
// fs.add_file("/a/b/file2.txt", "Another file")
// print(fs.ls("/a/b"))  # Output: ["file1.txt", "file2.txt", "c"]

// # Read file content
// print(fs.read_file("/a/b/file1.txt"))  # Output: "Hello, World!"


using namespace std;

class File{
    public:
    string name;
    string content;

    File(string name, string content){
        this->name = name;
        this->content = content;
    }

};

class Directory{
    public:
    string name;
    map<string, File*> files;
    map<string, Directory*> directories;

    Directory(string name){
        this->name = name;
    }

    void mkdir(string path){
        int pos = path.find('/');
        string curDir=path;
        // cout << curDir << endl;
        if(pos==-1){
            Directory *dir;
            if(directories.count(curDir)==0){
                dir = new Directory(curDir);
                directories[curDir] = dir;
            }
        }
        else{
            curDir = path.substr(0, pos);
            Directory *dir;
            if(directories.count(curDir)==0){
                dir = new Directory(curDir);
                directories[curDir] = dir;
            }
            else 
                dir = directories[curDir];
            dir->mkdir(path.substr(pos+1));
        }
    }

    vector<string> ls(string path){
        if(path.empty()){
            vector<string> res;
            for(auto file: files)
                res.push_back(file.first);
            for(auto dir: directories)
                res.push_back(dir.first);
            return res;
        }
        int pos = path.find('/');
        string curDir=path; 
        if(pos==-1){
            return directories[curDir]->ls("");
        } else {
            return directories[curDir]->ls(path.substr(pos+1));
        }
    }

    void add_file(string path, string content){
        
        int pos = path.find('/');
        string curDir = path;
        if(pos==-1){
            File* file = new File(curDir, content);
            this->files[curDir] = file;
        } else {
            curDir = curDir.substr(0, pos);
            this->directories[curDir]->add_file(path.substr(pos+1), content);
        }
    }

    string read_file(string path){
        int pos = path.find('/');
        string curDir = path;
        if(pos==-1){
            return files[curDir]->content;
        } else {
            curDir = curDir.substr(0, pos);
            return directories[curDir]->read_file(path.substr(pos+1));
        }
    }
};

class FileSystem{
    public:
    Directory *root;
    unordered_map<string, string> fileMap;

    FileSystem(){
        root = new Directory("");
    }

    void mkdir(string path){
        int pos = path.find('/');
        root->mkdir(path.substr(pos+1));
    }

    vector<string> ls(string path){
        int pos = path.find('/');
        return root->ls(path.substr(pos+1));
    }

    void add_file(string path, string content){
        int pos = path.find('/');
        root->add_file(path.substr(pos+1), content);
    }

    string read_file(string path){
        int pos = path.find('/');
        return root->read_file(path.substr(pos+1));
    }

};


int main(){
    FileSystem fs;
    fs.mkdir("/a/b");
    fs.mkdir("/a/c");
    for(auto fn: fs.ls("/a"))
        cout << fn << ", ";
    cout << endl;
    fs.add_file("/a/b/file1.txt", "Hello, World!");
    fs.add_file("/a/b/file2.txt", "Another file");
    cout << fs.read_file("/a/b/file1.txt") << endl;
    cout << fs.read_file("/a/b/file2.txt") << endl;
}