#!/usr/bin/python
# coding: utf-8

import urllib2, re

base_url = "http://commons.wikimedia.org"
char_list_url = "/wiki/Category:Bw.png_stroke_order_images"
headers = { "User-Agent":"Mozilla/5.0 (X11; U; Linux i686) Gecko/20071127 Firefox/2.0.0.11" }

while char_list_url:
	url = base_url+char_list_url
	url = url.replace( "&amp;", "&" )
	print url
	r = urllib2.Request(url, headers=headers)
	char_list = urllib2.urlopen( r ).read()
	char_list_url = re.findall( """<a href="([^"]*)" title="Category:Bw.png stroke order images">next [0-9]*</a>""", char_list )
	if char_list_url:
		char_list_url = char_list_url[0]
	else:
		char_list_url = None
		
	meta_urls = re.findall( """<a href="([^"]*\\.png)" title="File:([^"]*\\.png)">""", char_list )
	# create unified name-to-url-mapping:
	meta_url_dict = {}
	for x in meta_urls:
		meta_url_dict[ x[1] ] = x[0]
	
	for image_name in meta_url_dict:
		print image_name,
		meta_url = meta_url_dict[ image_name ]
		try:
			image_file = open( image_name, "r" )
			image_file.close()
			print "[skip]"
			continue # do not load images again
		except:
			pass
		meta = urllib2.urlopen( urllib2.Request(base_url+meta_url, headers=headers) ).read()
		#                          <a href="http://upload.wikimedia.org/wikipedia/commons/6/6a/%E5%AD%A6-bw.png"><img alt="File:学-bw.png" 
		image_url = re.findall( """<a href="(http://upload[^"]*\\.png)"><img alt="File:%(image_name)s" """ % locals(), meta )
		try:
			image_url = image_url[0]
			image = urllib2.urlopen( urllib2.Request(image_url, headers=headers) ).read()
			image_file = open( image_name, "w" )
			image_file.write( image )
			image_file.close()
			print "[OK]"
		except IndexError, e:
			print "[FAIL: %s]" % str(e)
