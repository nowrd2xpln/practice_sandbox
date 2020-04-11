#include <iostream>

int test01();
int test02();
int test03();


class Solution {
	public:
		int cnt;

		int numberOfSteps (int numb) {
			// validate number
			if(numb < 0) {
				std::cout << "Invalid number " << numb << std::endl;
				return numb;
			}
			if(numb == 0) return 0;

			for(cnt = 0; numb > 0; cnt++) {
				// Determine if number is odd or even
				if(numb & 1) { // Odd
					numb--;
				}
				else { // Even
					numb >>= 1;
				}
			}
			std::cout << "cnt: " << cnt << std::endl;
			return cnt;
		}
};

int main()
{
    int ret = 0;
	Solution sln;

    std::cout << "Hello World!\n" << std::endl;
    
	
	for(int x = 5; x >= 0; x--) {
		std::cout << x << " : " << sln.numberOfSteps(x) << std::endl;
	}
    test01();

    return ret;
}

int test01()
{
    int ret = 0;

    
    return ret;
}
