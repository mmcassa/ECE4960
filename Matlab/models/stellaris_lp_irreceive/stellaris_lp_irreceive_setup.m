% bit time specification 
ms = 0.001;
bit = [1 1 0 0];
bit1t =[0 4.8 5   6.8  ] * ms;      % bit 1
bit0t =[0 1.4 1.6 6.4  ] * ms;      % bit 0

% frame interval time specification 
bits = [5 0 0];         % output of 5 is only for debugging, state machine
                        % do not rely on this marker to run properly.
bitt = [0 0.2*ms 10*ms];

% array of data word
data_str = 1:5:50;

% convert it into strings of binary bits, ',' represent interval beween
% bits
data = [];
for i = data_str
    tmp = ['00000000' dec2bin(i)];
    data = [data ',' tmp(end-7:end)];
end

% then conver it into a time sequence.
for i=data
    
    if i == '0'
        bits = [bits bit];
        bitt = [bitt bitt(end)+0.2*ms+bit0t];
    elseif i == '1'
        bits = [bits bit];
        bitt = [bitt bitt(end)+0.2*ms+bit1t];
    elseif i == ','
        bits = [bits 0];
        bitt = [bitt bitt(end)+10*ms];
    end;
end