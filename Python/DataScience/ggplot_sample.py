from pandas import *
from ggplot import *

df = pandas.read_csv('hr_year.csv')
gp = ggplot(df, aes(x='yearID', y='HR')) + geom_point(color='red') + geom_line(color='red') \
+ ggtitle('HR by year') + xlab('year') + ylab('HR')

gp.show()

