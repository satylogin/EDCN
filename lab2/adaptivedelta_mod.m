lim = 10;
t = 0:0.001:lim;
y = sin(t);
plot(t, y);
f = pi/20;
d = 1/10;
k = 1.3;
hold on; 
    level = 0;
    delta = 0;
    last = 0;
    for i = f:f:lim
        q = t>= i;
        if (sin(i) >= level)
            if (last == 0)
                d = d * k;
            else 
                d = d / k;
            end
            last = 0;
            q = d.*q;
            delta = delta + q;
            level = level + d;
        elseif (sin(i) < level)
            if (last == 1)
                d = d * k;
            else 
                d = d / k;
            end
            last = 1;
            q = d.*q;
            delta = delta - q;
            level = level - d;
        end
    end
    plot(t, delta);
hold off;