from django.conf.urls import include
from django.urls import path as url
from blog.views import archive,create_blogpost 
urlpatterns = [ url('', archive, name='archive'), 
url('create/', create_blogpost, name='create_blogpost'), 
 ]
