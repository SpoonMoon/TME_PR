#include "Pair.h"

using namespace std;
using namespace pr;
 
int main_p () {
    vector<Pair> words;
    words.reserve(5000);
	
    ifstream input = ifstream("WarAndPeace.txt");
	
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::cout << "Parsing War and Peace" << endl;
	
    std::string s;
    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re( R"([^a-zA-Z])");
    while (input >> s) {
		// élimine la ponctuation et les caractères spéciaux
		s = regex_replace ( s, re, "");
		// passe en lowercase
		std::transform(s.begin(),s.end(),s.begin(),::tolower);
		
		// cherchons si le mot est déjà présent
		auto it = words.begin();
		while (it != words.end()) {
			if ((*it).Stringer() == s) {
				// trouvé
                                ++(*it);
				break;
			}
			++it;
		}
		if (it != words.end()) {
			// déjà trouvé
			continue;
		} else {
			words.push_back(Pair(s));
		}
	}
    input.close();
	
    std::cout << "Finished Parsing War and Peace" << endl;
	
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Parsing with took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms.\n";
	
	auto it = words.begin();
	while(it != words.end()){
		string compare = (*it).Stringer();
		if (compare == "war" || compare == "peace" || compare == "toto"){
			std::string mot = (*it).Stringer();
			std::cout << "Found a total of " << (*it).Inter() << " " << mot << std::endl;
		}
		++it;
	}
    return 0;
}

int main(){
	main_p();
	
	return 0;
}
