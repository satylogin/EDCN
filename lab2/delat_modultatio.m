lim = 10;
t = 0:0.001:lim;
y = sin(t);
plot(t, y);
f = pi/20;
d = 1/10;
hold on; 
    level = 0;
    delta = 0;
    for i = f:f:lim
        q = t>= i;
        q = d.*q;
        if (sin(i) >= level)   
            delta = delta + q;
            level = level + d;
        elseif (sin(i) < level)
            delta = delta - q;
            level = level - d;
        end
    end
    plot(t, delta);
hold off;