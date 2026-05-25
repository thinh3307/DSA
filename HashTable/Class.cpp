#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Student {
    string code;
    string name;
    double gpa;
    string klass;
};
class Registry {
public:
    void add(const Student &s) {
        byCode[s.code]=s;
        byClass[s.klass].push_back(s.code);
    }
    // Returns pointer to student, or nullptr if not found.
    const Student* find(const string &code) const {
        auto it=byCode.find(code);
        if(it==byCode.end()) return nullptr;
        return &it->second;
    }
    // Codes in a class, sorted ascending by code. Empty if class unknown.
    vector<string> list(const string &klass) const {
            auto it=byClass.find(klass);
            if(it==byClass.end()) return{};
            vector<string> codes=it->second;
            sort(codes.begin(),codes.end());
            return codes;

    }
    // Pointer to top-gpa student in a class (tie => smallest code). nullptr if empty.
    const Student* top(const string &klass) const {
        auto it=byClass.find(klass);
        if(it==byClass.end()) return {};
        const Student *best=nullptr;
        for(const string &code:it->second){
            const Student *s=&byCode.at(code);
            if(!best||s->gpa>best->gpa||(s->gpa==best->gpa&&s->code<best->code)) best=s;
        }
        return best;
    }
private:
    unordered_map<string, Student> byCode;
    unordered_map<string, vector<string>> byClass;
};
int main() {
    int n;
    cin >> n;
    Registry reg;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.code >> s.name >> s.gpa >> s.klass;
        reg.add(s);
    }
    int q;
    cin >> q;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "FIND") {
            string code; cin >> code;
            const Student* s = reg.find(code);
            if (!s) {
                cout << "NOT_FOUND\n";
            } else {
                cout << s->code << " " << s->name << " "
                     << fixed << setprecision(2) << s->gpa
                     << " " << s->klass << "\n";
            }
        } else if (cmd == "LIST") {
            string klass; cin >> klass;
            vector<string> codes = reg.list(klass);
            if (codes.empty()) {
                cout << "EMPTY\n";
            } else {
                for (size_t i = 0; i < codes.size(); i++) {
                    if (i) cout << " ";
                    cout << codes[i];
                }
                cout << "\n";
            }
        } else if (cmd == "TOP") {
            string klass; cin >> klass;
            const Student* s = reg.top(klass);
            if (!s) {
                cout << "EMPTY\n";
            } else {
                cout << s->code << " " << s->name << " "
                     << fixed << setprecision(2) << s->gpa << "\n";
            }
        }
    }
    return 0;
}