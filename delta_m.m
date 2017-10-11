t = 0:0.01:1;
x = sin(2*pi*t);

hold on
    plot(x);
    title('sinc pulse');
    xlabel('time');
    ylabel('amplitude');
    delta = 0.05;
    xn = zeros(1,100);
    for i = 1:99
        if x(i) >= xn(i)
            xn(i+1) = xn(i) + delta;
        else
            xn(i+1) = xn(i) - delta;
        end
    end
    stairs(xn,'black');
    plot(x)
hold off

y =zeros(1,100)
for j = 1:99
    if x(i) >=xn(i);
        y(i)=1
    else
        y(i)=0
    end
end
