%
% Plotting facility
%

%% open plot facility with data description setup
data.keyword = 'FilteredGmeter';      % the first column of each line
data.columns = [ 2 3 4 ];     % data columns
data.Ts = 0.01;                 % sample time, zero means time is in columns(1)-1
data.Twindow = 10;              % time span of the plot window
data.YRange = [-1.2 1.2];       % range of Y axis

tcpip_plot(data);