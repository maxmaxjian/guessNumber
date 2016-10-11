#include <iostream>
#include <algorithm>

class solution {
  public:
    int getMoneyAmount(int n) {
        std::vector<int> money;
        for (int pick = 1; pick <= n; pick++)
            money.push_back(guessNum(n, pick));

        std::for_each(money.begin(), money.end(), [](int i){std::cout << i << " ";});
        std::cout << std::endl;
        
        return *std::max_element(money.begin(), money.end());
    }

  private:
    int guessNum(int n, int pick) {
        int result = 0;
        int left = 1, right = n;
        while (left < right-1) {
            int mid = (left+right)/2;
            if (mid == pick)
                break;
            else if (mid < pick) {
                result += mid;
                left = mid;
            }
            else {
                result += mid;
                right = mid;
            }
        }
        if (left < right-1) {
            if (left != pick)
                result += left;
        }
        return result;
    }
};

int main() {
    int n = 10;
    solution soln;
    int maxmin = soln.getMoneyAmount(n);
    std::cout << maxmin << std::endl;
}
