#include <bits/stdc++.h>

using namespace std;


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

class File{
    string name;
    string size;
    string fileId;
};

class Directory{
    public:
    unordered_map<string, Directory*> dirs;
    unordered_map<string, File*> files;
    string name;
    string metadata;

    Directory(){
        this->name = "";
    }

    Directory(string name){
        this->name = name;
    }

    bool mkdir(string name){
        if(name=="")
            return true;
        int pos = name.find('/');
        string dirName, remPath;

        if(pos==-1) {
            dirName = name;
        } else {
            dirName = name.substr(0,pos);
            remPath = name.substr(pos+1);
        }
        // cout << pos << " " << dirName << " " << remPath << endl;
        if(dirs.find(dirName)!=dirs.end()){
            return dirs[dirName]->mkdir(remPath);
        }
        
        Directory *newDir =  new Directory(dirName);
        dirs[dirName] = newDir;
        return dirs[dirName]->mkdir(remPath);
    }

    vector<string> ls(string path){

        // cout << "LS   -- " << path << endl;
        if(path==""){
            vector<string> res;
            for(auto file: files)
                res.push_back(file.first);
            // cout << this->name << "  " << this->dirs.size() << endl;
            for(auto dir: dirs)
                res.push_back(dir.first);
            // cout << res.size() << endl;
            return res;
        }
        int pos = path.find('/');

        string dirName, remPath;

        if(pos==-1) {
            dirName = path;
        } else {
            dirName = path.substr(0,pos);
            remPath = path.substr(pos+1);
        }
        // cout << pos << " " << dirName << " " << remPath << endl;
        return dirs[dirName]->ls(remPath);
    }

};

class FileSystem{
    public:
    Directory root;
    map<string, string> fileContents;

    FileSystem(){
    }

    bool mkdir(string path){
        path = path.substr(path.find('/')+1);
        // cout<<path<<endl;
        return root.mkdir(path);
    }

    vector<string> ls(string path){
        path = path.substr(path.find('/')+1);
        // cout << path << endl;
        return root.ls(path);
    }   
};

int main(){

    FileSystem fs;

    fs.mkdir("/a/b");
    fs.mkdir("/a/c");
    vector<string> res = fs.ls("/a");
    for(auto r: res)
        cout << r << " ";
    cout << endl;
    return 0;
}