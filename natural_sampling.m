
t = 0:0.001:1;
fc =100;
fm =20;
a = 5;
vc = square(2*pi*fc*t);
vm = 5.*sin(2*pi*fm*t);
n = length(vc);
for i = 1:n
    if (vc(i)<=0)
        vc(i) = 0;
    else
        vc(i) = 1;
    end
end
y = vc.*vm; % Multiplying the carrier & message signal
subplot(3,1,1);
plot(t,vm); % plotting the message signal
xlabel('Time Axis');
ylabel('Amplitude');
title('Message Signal');
subplot(3,1,2);
plot(t,vc); % plotting the carrier signal
xlabel('Time Axis');
ylabel('Amplitude');
title('Carrier Signal');
axis([0 1 0 1.5]);% to set scaling of x & y axis for better visualization
subplot(3,1,3);
plot(t,y); 
% plotting the naturally sampled signal thus generated
xlabel('Time Axis');
ylabel('Amplitude');
title('Sampled Signal (Natural)');
axis([0 1 -a-3 a+3]);