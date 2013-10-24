// 题目：http://oj.leetcode.com/problems/word-ladder-ii/
//
// 题意：给定开始单词，和结束的单词，在给定的字典中寻找最短的路劲，通过该路径开
//       始的单词能够转化成结束的单词。具体转化的条件是：两个单词间只能有一个字
//       母不相同。
//
// 解法：1. 在给定的字典中构造出邻接表。2. BFS每个节点，从而得到开始节点都每个节
//      点的最短距离。3. DFS构造路径。
//
//      参考了网上人家的讨论，一开始我是直接用DFS，可是数据大的时候就TLE，而
//      且DFS的方式也不对。另外，在做这个题目的过程中，知道了unordered_map的效率
//      貌似比map高，添加新的元素以及查找都是O(1)。

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<vector<string> > findLadders(string start, string end,
                                      unordered_set<string> &dict) {
    adj.clear();
    vs.clear();

    dict.insert(start);
    dict.insert(end);
    buildAdj(dict);

    int startV, endV;
    for (startV = 0; vs[startV] != start; startV++);
    for (endV = 0; vs[endV] != end; endV++);
    vector<int> dis(vs.size());
    vector<vector<int> > pre(vs.size());
    queue<int> q;
    q.push(startV);

    while (not q.empty()) {
      int t = q.front();
      q.pop();

      if (t == endV) {
        break;
      }

      int d = dis[t] + 1;
      for (int i = 0; i < adj[t].size(); i++) {
        int v = adj[t][i];
        if (pre[v].empty()) {
          q.push(v);
          dis[v] = d;
          pre[v].push_back(t);
        } else if (dis[v] == d) {
          pre[v].push_back(t);
        }
      }
    }

    vector<vector<string> > result;
    vector<string> path;
    getAns(endV, startV, pre, path, result);

    return result;
  }

 private:
  vector<vector<int> > adj;
  vector<string> vs;

  void getAns(int cur, int startV, vector<vector<int> > &pre,
              vector<string> &path, vector<vector<string> > &ans) {
    path.push_back(vs[cur]);
    if (cur == startV) {
      ans.push_back(vector<string>());
      for (auto it = path.rbegin(); it != path.rend(); it++)
        ans.back().push_back(*it);
    } else {
      for (int i = 0; i < pre[cur].size(); i++) {
        getAns(pre[cur][i], startV, pre, path, ans);
      }
    }

    path.pop_back();
  }

  void buildAdj(unordered_set<string>& dict) {
    map<string, int> ids;
    for (auto it = dict.begin(); it != dict.end(); it++) {
      ids[*it] = vs.size();
      vs.push_back(*it);
    }

    adj.resize(vs.size());

    for (int i = 0; i < vs.size(); i++) {
      for (int j = 0; j < vs[i].size(); j++) {
        for (char c = 'a'; c <= 'z'; c++) {
          if (c != vs[i][j]) {
            string w = vs[i];
            w[j] = c;
            if (dict.find(w) != dict.end())
              adj[i].push_back(ids[w]);
          }
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  unordered_set<string> set1 = {"kid","tag","pup","ail","tun","woo","erg",
    "luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet",
    "pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex",
    "jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum",
    "fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis",
    "ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore",
    "pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm",
    "ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map",
    "ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin",
    "feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy",
    "fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab",
    "jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire",
    "irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag",
    "amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave",
    "buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn",
    "rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie",
    "mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day",
    "apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can",
    "pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par",
    "wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev",
    "axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art",
    "ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw",
    "sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey",
    "saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let",
    "see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam",
    "zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod",
    "mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass",
    "dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf",
    "mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib",
    "eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut",
    "ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva",
    "lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat",
    "wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen",
    "odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg",
    "put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red",
    "doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop",
    "tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag",
    "mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig",
    "lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins",
    "con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot",
    "sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci",
    "job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed",
    "ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk",
    "gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip",
    "han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil",
    "rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag",
    "elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun",
    "ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai",
    "sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len",
    "air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin",
    "dun","pat","ten","mob"};

  vector<vector<string> > re = s.findLadders("cet", "ism", set1);
  for (int i = 0; i < re.size(); i++) {
    for (int j = 0; j < re[i].size(); j++) {
      cout << re[i][j] << " ";
    }
    cout << endl;
  }

  unordered_set<string> set2 = {"si","go","se","cm","so","ph","mt","db","mb",
      "sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to",
      "ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn",
      "au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge",
      "th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa",
      "pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn",
      "mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr",
      "sq","ye"};
  re = s.findLadders("qa", "sq", set2);
  for (int i = 0; i < re.size(); i++) {
    for (int j = 0; j < re[i].size(); j++) {
      cout << re[i][j] << " ";
    }
    cout << endl;
  }

  unordered_set<string> set3 = {"hot","dot","dog","lot","log"};
  re = s.findLadders("hit", "cog", set3);
  for (int i = 0; i < re.size(); i++) {
    for (int j = 0; j < re[i].size(); j++) {
      cout << re[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
