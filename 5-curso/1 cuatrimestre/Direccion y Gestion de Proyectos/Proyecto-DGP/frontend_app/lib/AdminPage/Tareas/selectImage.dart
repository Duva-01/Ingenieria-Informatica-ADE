import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:path/path.dart';


class ImageSelectionScreen extends StatefulWidget {
  @override
  _ImageSelectionScreenState createState() => _ImageSelectionScreenState();
}

class _ImageSelectionScreenState extends State<ImageSelectionScreen> {
  List<String> imagePaths = [];

  @override
  void initState() {
    super.initState();
    _loadImagesFromAssets();
  }

  Future<void> _loadImagesFromAssets() async {
    final manifestContent = await rootBundle.loadString('AssetManifest.json');
    final Map<String, dynamic> manifestMap = json.decode(manifestContent);
    final imagePaths = manifestMap.keys.where((String key) => key.startsWith('assets/pictogramas/')).where((String path) => _isImageFile(path)).toList();
    setState(() {
      this.imagePaths = imagePaths;
    });
  }

  bool _isImageFile(String path) {
    final ext = extension(path).toLowerCase();
    return ext == '.jpg' || ext == '.jpeg' || ext == '.png' || ext == '.gif';
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Seleccionar Imagen'),
      ),
      body: ListView.builder(
        itemCount: imagePaths.length,
        itemBuilder: (context, index) {
          return ListTile(
            title: Image.asset(imagePaths[index]),
            onTap: () => Navigator.of(context).pop(imagePaths[index]),
          );
        },
      ),
    );
  }
}
