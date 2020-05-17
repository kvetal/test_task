#include <iostream>
#include <vector>

void print_vector(std::vector<int> v){
	for(int t:v)
	{
		std::cout << t << '\t';
	}
	std::cout << '\n';
}
int main()
{
	std::vector<int> v1 {1,1,2,3,4,1,6,33,88,45,45,2,8,34,8,9,9};
	print_vector(v1);
	for (int i = 0; i < v1.size()-1;++i)
		for(int j = i+1;j <v1.size();++j)
		{		
			if (v1[i] == v1[j])
				v1.erase(v1.begin()+j);
		}
	print_vector(v1);
}
