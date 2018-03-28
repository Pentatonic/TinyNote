from pandas import *
from ggplot import *

def lineplot(csv):
    df = pandas.read_csv(csv)
    gp = ggplot(df, aes(x='yearID', y='HR')) \
        + geom_point(color='red') + geom_line(color='red') \
        + ggtitle('HR by year') + xlab('year') + ylab('HR')
    return gp

def lineplot_compare(hr_by_team_year_sf_la_csv):
    # Write a function, lineplot_compare, that will read a csv file
    # called hr_by_team_year_sf_la.csv and plot it using pandas and ggplot.
    #
    # This csv file has three columns: yearID, HR, and teamID. The data in the
    # file gives the total number of home runs hit each year by the SF Giants 
    # (teamID == 'SFN') and the LA Dodgers (teamID == "LAN"). Produce a 
    # visualization comparing the total home runs by year of the two teams. 
    #
    # You can see the data in hr_by_team_year_sf_la_csv
    # at the link below:
    # https://s3.amazonaws.com/content.udacity-data.com/courses/ud359/hr_by_team_year_sf_la.csv
    #
    # Note that to differentiate between multiple categories on the 
    # same plot in ggplot, we can pass color in with the other arguments
    # to aes, rather than in our geometry functions. For example, 
    # ggplot(data, aes(xvar, yvar, color=category_var)). This might help you 
    # in this exercise.

    df = pandas.read_csv(hr_by_team_year_sf_la_csv)
    gg = ggplot(df, aes(x='yearID', y='HR', color='teamID')) \
        + geom_point() + geom_line() \
        + ggtitle('HR by year') + xlab('year') + ylab('HR')
    return gg
from pandas import *
from ggplot import *

def plot_weather_data(turnstile_weather):
    '''
    You are passed in a dataframe called turnstile_weather. 
    Use turnstile_weather along with ggplot to make a data visualization
    focused on the MTA and weather data we used in assignment #3.  
    You should feel free to implement something that we discussed in class 
    (e.g., scatterplots, line plots, or histograms) or attempt to implement
    something more advanced if you'd like.  

    Here are some suggestions for things to investigate and illustrate:
     * Ridership by time of day or day of week
     * How ridership varies based on Subway station (UNIT)
     * Which stations have more exits or entries at different times of day
       (You can use UNIT as a proxy for subway station.)

    If you'd like to learn more about ggplot and its capabilities, take
    a look at the documentation at:
    https://pypi.python.org/pypi/ggplot/
     
    You can check out:
    https://s3.amazonaws.com/content.udacity-data.com/courses/ud359/turnstile_data_master_with_weather.csv
     
    To see all the columns and data points included in the turnstile_weather 
    dataframe. 
     
    However, due to the limitation of our Amazon EC2 server, we are giving you a random
    subset, about 1/3 of the actual data in the turnstile_weather dataframe.
    '''

    t = pandas.read_csv(turnstile_weather)
    df = t[['DATEn', 'ENTRIESn_hourly']]
    # group entries by date
    df = df.groupby('DATEn', as_index=False).agg({"ENTRIESn_hourly": "sum"})
    df['exit'] = Series('0', index=df.index)
    df.rename(columns={'ENTRIESn_hourly': 'ridership'}, inplace=True)
    print df

    df2 = t[['DATEn', 'EXITSn_hourly']]
    df2 = df2.groupby('DATEn', as_index=False).agg({"EXITSn_hourly": "sum"})
    df2['exit'] = Series('1', index=df.index)
    df2.rename(columns={'EXITSn_hourly': 'ridership'}, inplace=True)
    print df2

    plot = ggplot(pandas.concat([df, df2]), aes(x='DATEn', y='ridership', color='exit')) \
        + geom_point() + geom_line() \
        + ggtitle('entries by date') + xlab('date') + ylab('entries')
    return plot

#print lineplot('hr_year.csv')
#print lineplot_compare('hr_by_team_year_sf_la.csv')
print plot_weather_data('turnstile_data_master_with_weather.csv')

