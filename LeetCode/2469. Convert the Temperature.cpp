
public:
    vector<double> convertTemperature(double celsius) {
            double Kelvin = celsius + 273.15;
    double Fahrenheit = celsius * 1.80 + 32.00;

    vector<double> koko;

    koko.push_back(Kelvin);
    koko.push_back(Fahrenheit);

    return koko;
    }
