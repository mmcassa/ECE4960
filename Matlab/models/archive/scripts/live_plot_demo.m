function live_plot_demo(varargin)
%% DEMO of the LIVE PLOT UTILITY
% This file demonstrates how to use live plot utility to view a real-time
% ascii coded signal. The test signal is generated using a dummy tcpip server.
%
% To try out this demo, open two MATLAB instance.
%
% Run the following command in one instance
%    live_plot_demo server
% This will start a dummy server that ready to send out data.
%
% Then, run the following command in anther instance
%    live_plot_demo
% This will bring up a GUI. Click start and then you should see the plot of
% a few sine waves and a square wave in realtime. 
% 
% The dummy server will
% generate 30 second worth of data and stop. To run the it again, it is
% necessary to stop the plot and then start the server and plot again using
% instructions above.
%
% Author: Sippey
% Date: 04/16/2014

%% First, open plot window with data description setup
data.keyword = 'TestPlot';      % the first column of each line
data.columns = [ 2 3 4 5 ];     % data columns
data.Ts = 0.02;                 % sample time
data.Twindow = 10;              % time span of the plot window
data.YRange = [-5 5];           % range of Y axis, -1 to be adaptive.

conn.type = 'tcpip';         % type of communication
conn.host = 'localhost';     % host to connect to
conn.port = 12345;           % port to connect to

% COM port
% datasrc.type = 'serial';         % type of communication
% datasrc.port = 1;                % port to connect to, COM1
% datasrc.baud = 115200;           % baud rate
% the dummy server do not work for COM port setting


if nargin == 0
    live_plot(data, conn); 
elseif strcmp(varargin{1},'server')
    % open a dummy server
    svr = tcpip('localhost', conn.port, 'NetworkRole', 'server');
    try 
        disp('Waiting for connection....');
        fopen(svr);
        disp('Client connected.');

        a1 = 4;
        f1 = 1.3;

        a2 = 2;
        f2 = 0.27;

        a3 = 3;
        f3 = 0.43;

        a4 = 3;

        for t = 0 : data.Ts : (data.Twindow*3)
            sample = [a1*sin(2*pi*f1*t) ;
                    a2*cos(2*pi*f2*t) ;
                    a3*sin(2*pi*f3*t+pi/2) ;
                    a4*(mod(t, 2)>1)];
            fwrite(svr,sprintf( '%s %f %f %f %f\r\n', data.keyword, sample));
            %pause in bigger step to make it more accurate
            if mod(t/data.Ts,10)==9
            	pause(data.Ts*10);
            end
        end
        
        disp('Finished generating data.');
        fclose(svr);
        delete(svr);
    catch 
        fclose(svr);
        delete(svr);
    end
end