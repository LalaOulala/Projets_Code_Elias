import folium

# Création de la carte de l'Europe
europe_map = folium.Map(location=[48.85, 2.35], zoom_start=4)

# Ajout de marqueurs pour chaque front de guerre
folium.Marker(location=[46.2276, 2.2137], popup='Front français').add_to(europe_map)
folium.Marker(location=[42.5, 1.5], popup='Front espagnol').add_to(europe_map)
folium.Marker(location=[42.8747, 12.5674], popup='Front italien').add_to(europe_map)

# Ajout de cercles pour représenter les zones contrôlées par chaque alliance
folium.Circle(location=[48.85, 2.35], radius=150000, color='#3186cc', fill=True, fill_color='#3186cc').add_to(europe_map)
folium.Circle(location=[48.85, 2.35], radius=300000, color='#ffffff', fill=True, fill_color='#ffffff').add_to(europe_map)
folium.Circle(location=[48.85, 2.35], radius=450000, color='#ff0000', fill=True, fill_color='#ff0000').add_to(europe_map)

# Affichage de la carte
europe_map.save('europe_war.html')
