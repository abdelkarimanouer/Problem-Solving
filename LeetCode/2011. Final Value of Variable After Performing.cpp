
int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string oper : operations) {
            if (oper[2] == '+') X++;
            else if (oper[0] == '+') ++X;
            else if (oper[2] == '-') X--;
            else if (oper[0] == '-') --X;
        }
        return X;
    }
