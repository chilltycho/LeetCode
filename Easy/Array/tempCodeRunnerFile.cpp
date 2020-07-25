int i = 0, j = 0;
    while (j < nums.size() && i <= j)
    {

        if (nums[i] == 0)
        {
            while (nums[j] == 0 && j < nums.size())
                j++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }