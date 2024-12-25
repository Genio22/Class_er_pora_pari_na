Mohammad Abrar Jawad
// Flutter code for the Kaaba History App
import 'package:flutter/material.dart';
import 'package:flutter_localizations/flutter_localizations.dart';
import 'package:intl/intl.dart'; // For localization

void main() {
  runApp(KaabaHistoryApp());
}

class KaabaHistoryApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Kaaba History App',
      theme: ThemeData(
        primarySwatch: Colors.green,
      ),
      supportedLocales: [
        Locale('en', ''),
        Locale('bn', ''),
        Locale('ar', ''),
      ],
      localizationsDelegates: [
        GlobalMaterialLocalizations.delegate,
        GlobalWidgetsLocalizations.delegate,
      ],
      home: LanguageSelectorPage(),
    );
  }
}

class LanguageSelectorPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Kaaba History'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            LanguageButton(
              language: 'English',
              locale: Locale('en', ''),
            ),
            LanguageButton(
              language: 'বাংলা',
              locale: Locale('bn', ''),
            ),
            LanguageButton(
              language: 'العربية',
              locale: Locale('ar', ''),
            ),
          ],
        ),
      ),
    );
  }
}

class LanguageButton extends StatelessWidget {
  final String language;
  final Locale locale;

  LanguageButton({required this.language, required this.locale});

  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      onPressed: () {
        Navigator.push(
          context,
          MaterialPageRoute(
            builder: (context) => HomePage(locale: locale),
          ),
        );
      },
      child: Text(language),
    );
  }
}

class HomePage extends StatelessWidget {
  final Locale locale;

  HomePage({required this.locale});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(getTitle(locale)),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              getContent(locale),
              style: TextStyle(fontSize: 16.0),
            ),
          ],
        ),
      ),
    );
  }

  String getTitle(Locale locale) {
    switch (locale.languageCode) {
      case 'en':
        return 'History of the Kaaba';
      case 'bn':
        return 'কাবার ইতিহাস';
      case 'ar':
        return 'تاريخ الكعبة';
      default:
        return 'History of the Kaaba';
    }
  }

  String getContent(Locale locale) {
    switch (locale.languageCode) {
      case 'en':
        return 'The Kaaba is the most sacred site in Islam, located in the city of Mecca. It is central to the rituals of Hajj and Umrah.';
      case 'bn':
        return 'কাবা ইসলাম ধর্মের পবিত্রতম স্থান, যা মক্কা শহরে অবস্থিত। এটি হজ ও উমরাহের গুরুত্বপূর্ণ অংশ।';
      case 'ar':
        return 'الكعبة هي أقدس موقع في الإسلام وتقع في مدينة مكة. وهي مركزية في شعائر الحج والعمرة.';
      default:
        return '';
    }
  }
}