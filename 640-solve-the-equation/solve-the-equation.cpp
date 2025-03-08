class Solution {
public:
string solveEquation(string equation) {
    vector<string> polynominals = splitStringByDelimiter(equation, "=");

    pair<int, int> f1 = simplify_polynomial(polynominals[0]);
    cout <<  f1.first << " " << f1.second << std::endl;

    pair<int, int> f2 = simplify_polynomial(polynominals[1]);
    cout <<  f2.first << " " << f2.second << std::endl;
    if ((f1.first == f2.first) && (f1.second == f2.second))
    return "Infinite solutions";

    if ((f1.first == f2.first) && (f1.second != f2.second)) return "No solution";

    return "x=" + to_string((f2.second - f1.second) / (f1.first - f2.first));
}

// f(x) = ax + b
pair<int, int> simplify_polynomial(string _poly) {
    pair<int, int> _pair;
    int _b = 0, _a = 0;

    regex pattern(R"(([-+]?\d*)(x*)?)");

    sregex_iterator  begin = sregex_iterator(_poly.begin(), _poly.end(), pattern);
    sregex_iterator  end   = sregex_iterator();

    for (sregex_iterator it = begin; it != end; it++) {
        smatch match = *it;
        string coeff = match[1].str();
        string var = match[2].str();

        if (!var.empty()) {
            if (coeff == "+" || coeff.empty()) _a += 1;
            else if (coeff == "-") _a -= 1;
            else _a += stoi(coeff);

            _pair.first = _a;
        } else {
            if (!coeff.empty()) _b += stoi(coeff);
            _pair.second = _b;
        }
    }

    return _pair;
}

vector<string> splitStringByDelimiter(string s, string delim) {
    vector<string> all_substr;
    std::size_t index = s.find(delim, 0);
    string sub_str  = s.substr(0, index);
    string new_string = s.substr(index+1);

    while (index != string::npos) { 
        if (sub_str != delim && sub_str.size() >= 1) {
            all_substr.push_back(sub_str);
        }

        index = new_string.find(delim, 0);
        sub_str  = new_string.substr(0, index);
        new_string = new_string.substr(index+1);
    }

    if (sub_str != delim && sub_str.size() >= 1) {
        all_substr.push_back(sub_str);
    }

    return all_substr;
}
};