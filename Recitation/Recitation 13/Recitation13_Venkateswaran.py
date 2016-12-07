from googleplaces import GooglePlaces, types, lang

#Retrieve API KEY
fname = "config"
with open(fname, 'r') as f:
	API_KEY = f.readline().strip()

google_places = GooglePlaces(API_KEY)

query_result = google_places.nearby_search(
		location='Boulder, Colorado', keyword='University',
		radius=20000, types=[types.TYPE_UNIVERSITY])

for place in query_result.places:
	print "Name"
	print place.name
	print "Location"
	print place.geo_location
	print "ID"
	print place.place_id
	print "\n"
	
	#for photo in place.photos:
		#photo.get(macheight=500, maxwidth=500)
