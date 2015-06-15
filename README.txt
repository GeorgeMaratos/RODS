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
