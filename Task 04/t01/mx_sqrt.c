int mx_sqrt(int x){
        if (x <= 0){
                return 0;
        }
        int result = 1;
        int i = 1;
        while (result < x){
                result = i * i;
                i++;
        }
        i -= 1;
        if (x != i * i){
                return 0;
        }
        return i;
}
