
auto init =[]()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    string addStrings(string num1, string num2) {

        int carry = 0;
        string ans;

        int index1 = num1.size()-1;
        int index2 = num2.size()-1;

        while (num1.size() || num2.size() || carry) {
            int digit1 = 0, digit2 = 0;
            if (num1.size() > 0) {
                digit1 = num1[index1] - '0';
                index1--;
                num1.pop_back();
            }
            if (num2.size() > 0) {
                digit2 = num2[index2] - '0';
                index2--;
                num2.pop_back();
            }
            int sum = digit1 + digit2 + carry;
            char ch = '0' + (sum % 10);
            ans = ch + ans;
            carry = sum / 10;
        }
        return ans;
    }
};
