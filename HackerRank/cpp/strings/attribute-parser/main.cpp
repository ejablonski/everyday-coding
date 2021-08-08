// https://www.hackerrank.com/challenges/attribute-parser
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;

namespace TagParser
{
    class Tag {
    public:
        Tag(string s) {
            name = s;
        }

        string getName() {
            return name;
        }

        void addChild(string s) {
            Tag *c = new Tag(s);
            children.push_back(c);
        }

        Tag* getChild(string s) {
            if(children.size() == 0) {
                return nullptr;
            } else {
                for(auto const i : children) {
                    if(i->getName() == s)
                        return i;
                }
            }
            return nullptr;
        }

        Tag* getLastOpenChild() {
            if(children.size() == 0 || children.back()->isClosed()) {
                return this;
            } else {
                return children.back()->getLastOpenChild();
            }
        }

        void addData(string k, string v) {
            auto p = make_pair(k, v);
            data.push_back(p);
        }

        string getValue(string k) {
            for(auto const i : data) {
                if(get<0>(i) == k)
                    return get<1>(i);
            }
            return "";
        }

        void closeTag() {
            closed = true;
        }

        bool isClosed() {
            return closed;
        }

        void print(int tab) {
            string tabs = "";
            for(int i = 0; i < tab; i++) {
                tabs.insert(0, "\t");
            }
            cout << tabs << name << " ";
            for(auto const j : data) {
                cout << "{" << get<0>(j) << ", " << get<1>(j) << "}, ";
            }
            cout << endl;
            for(auto const k : children) {
                k->print(tab + 1);
            }
            cout << tabs << name << " closed? ";
            if(closed)
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }

    private:
        string name;
        vector<pair<string, string>> data;
        vector<Tag*> children;
        bool closed = false;
    };

    void objectify(vector<string> &v, vector<TagParser::Tag*> &o) {
        vector<string> words;
        for(auto const i : v) {
            istringstream iss(i);
            string w;

            while(iss >> w) {
                words.push_back(w);
            }
        }

        for(int j = 0; j < words.size(); j++) {
            // new tag open
            if(words[j].find('<') != string::npos && words[j].find("</") == string::npos) {
                string tag_name = words[j].substr(1, words[j].size() - 1);
                if(tag_name.find('>') != string::npos) {
                    tag_name = tag_name.substr(0, words[j].size() - 2);
                }

                if(o.size() == 0) {
                    TagParser::Tag *t = new TagParser::Tag(tag_name);
                    o.push_back(t);
                } else if(o.back()->isClosed()) {
                    TagParser::Tag *t = new TagParser::Tag(tag_name);
                    o.push_back(t);
                } else {
                    o.back()->getLastOpenChild()->addChild(tag_name);
                }
            }

            // key-value
            if(words[j].find('=') != string::npos) {
                string key = words[j - 1];
                string value = words[j + 1];
                value.erase(remove(begin(value), end(value), '"'), end(value));
                value.erase(remove(begin(value), end(value), '>'), end(value));
                o.back()->getLastOpenChild()->addData(key, value);
            }

            // tag close
            if(words[j].find("</") != string::npos) {
                o.back()->getLastOpenChild()->closeTag();
            }
        }
    }

    void printTree(vector<TagParser::Tag*> v) {
        for(auto const i : v) {
            i->print(0);
        }
    }
}

int main(int argc, char **argv)
{
    int l;
    int q;
    vector<string> source;
    vector<string> queries;
    vector<TagParser::Tag*> objects;

    scanf("%i %i", &l, &q);
    // clear buffer to avoid reading empty line
    cin.clear();
    cin.ignore(10000,'\n');
    
    // read lines with source code
    for(int i = 0; i < l; i++) {
        string line;
        getline(cin, line);
        source.push_back(line);
    }
    
    // read lines with queries to find
    for(int i = 0; i < q; i++) {
        string line;
        getline(cin, line);
        queries.push_back(line);
    }

    TagParser::objectify(source, objects);
    // TagParser::printTree(objects);

    for(auto const i : queries) {
        int dot = 0;
        vector<string> qt;
        string qv;
        int dots = 0;
        for(int j = 0; j < i.size(); j++) {
            if(i[j] == '.') {
                string tmp = i.substr(dot, j - dot);
                qt.push_back(tmp);
                dot = j + 1;
            }
            if(i[j] == '~') {
                string tmp = i.substr(dot, j - dot);
                qt.push_back(tmp);
                qv = i.substr(j + 1, i.size());
            }
        }
        TagParser::Tag *tmp = nullptr;
        for(int k = 0; k < qt.size(); k++) {
            if(k == 0) {
                for(auto const o : objects) {
                    if(o->getName() == qt[k]) {
                        tmp = o;
                    }
                }
                if(tmp == nullptr) {
                    cout << "Not Found!" << endl;
                    break;
                }
            } else if(tmp->getChild(qt[k]) == nullptr) {
                cout << "Not Found!" << endl;
                break;
            } else {
                tmp = tmp->getChild(qt[k]);
            } 
            
            if(k == qt.size() - 1 && tmp != nullptr) {
                if(tmp->getValue(qv) != "") {
                    cout << tmp->getValue(qv) << endl;
                } else {
                    cout << "Not Found!" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
