fs = 20;
t = 0:1/fs:1-1/fs;
x = sin(2*pi*t);
stem(t,x)
hold on;
plot(t,x)
stairs(t,x)
hold off;