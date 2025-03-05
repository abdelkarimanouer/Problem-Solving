    public string DefangIPaddr(string address) {
        string str = address.Replace(".", "[.]");
        return str;
    }
