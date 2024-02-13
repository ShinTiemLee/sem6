from django.urls import re_path,path
from django.contrib import admin
from . import views
urlpatterns = [
	re_path('', views.index, name='index')
]

