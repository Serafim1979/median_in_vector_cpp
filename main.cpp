#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
    // верните {true, медиана}, если она существует,
    // то есть вектор непустой,
    // иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению,
    // так как его придётся немного подпортить, чтобы вернуть ответ
    pair<bool, double> res;
    bool check;
    double value = 0;
    if (samples.empty())
    {
        check = false;
        value = 0;
        res = std::make_pair(check, value);
        return res;
        check = true;
        value = samples[samples.size() / 2];
        res = std::make_pair(check, value);
        return res;
    }

    sort(samples.begin(), samples.end());
    if(samples.size() == 1)
    {
        check = true;
        value = samples[samples.size()];
        res = std::make_pair(check, value);
        return res;
    }
    else if (samples.size() % 2 == 0)
    {
        check = true;
        value = (samples[samples.size() / 2] + samples[samples.size() / 2 - 1]) / 2;
        res = std::make_pair(check, value);
        return res;
    }
    else
    {
        check = true;
        value = samples[samples.size() / 2];
        res = std::make_pair(check, value);
        return res;
    }
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples);
    if (result.first) {
        cout << result.second << endl;
    } else {
        cout << "Empty vector"s << endl;
    }
}