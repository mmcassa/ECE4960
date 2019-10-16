s1= tcpip('localhost', 12201);
fopen(s1);
accX=[];
accY=[];
accZ=[];
str='';
sen=[];
j=1;
x=0;

ts = 0.01;

try 
while(j<1010)
    s=fgetl(s1);
    ss= strsplit(s,' ');
    accX(j)=str2num(ss{2});
    accY(j)=str2num(ss{3});
    accZ(j)=str2num(ss{4});
    x(j)=j;

    if mod(j,5)==0 
        if(j>200)
            x1=x(j-200:j);
            accX1=accX(j-200:j);
            accY1=accY(j-200:j);
            accZ1=accZ(j-200:j);
            xmin=j-200;
            xmax=j;
        else
            x1=x;
            accX1=accX;
            accY1=accY;
            accZ1=accZ;
            xmin=0;
            xmax=200;
        end


        x1=x1*ts;
        plot(x1,accX1,x1,accY1,x1,accZ1);
        xrange = [xmin xmax]*ts;
        axis([xrange 0 4096]);


        drawnow;
    end
    j=j+1;

end;

catch e
    fclose(s1);
end

fclose(s1);
delete(s1);
clear s1;