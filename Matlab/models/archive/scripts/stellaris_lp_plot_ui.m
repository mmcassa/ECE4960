%
% Plotting facility
%

%% open the diagram and download the plot
open_system('stellaris_lp_plot');
% build system and download to stellaris


%% open plot facility with data description setup
data.keyword = 'TestPlot';      % the first column of each line
data.columns = [ 2 3 4 5 ];     % data columns
data.Ts = 0.02;                 % sample time, zero means time is in columns(1)-1
data.Twindow = 10;              % time span of the plot window
data.YRange = [-0.1 3.5];       % range of Y axis

live_plot(data);