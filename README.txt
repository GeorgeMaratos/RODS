Rod Cut
    -- price array p, length n
    Cut-Rod(p, n)
        if n = 0 then
            return 0
        end if
        q := MinInt
        for i in 1 .. n loop
            q = max(q, p(i) + Cut-Rod(p, n-i)
        end loop
        return q


test file format:

first line is a single integer specifying the size of rod
second line is a string of integers separated by spaces defining the cost of each cut


usage:

type "make"

run: ./rods <test_file>
