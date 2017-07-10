# Resample_spectrum_c
you must mkdir of spectrum/ and result/,
in spectrum/ store the original spectrum file of band 350nm to 2500nm of two columns
such as: 350  0.0021
         351  0.234
         352  0.0245
         ...
         2500 0.291
in result/ generate the resample result of different sensors

in this programme , includes landsat8-OLI  MERIS  Hyperion  AVRIS  MODIS sensors 
you can also choose MERIS sensor as user-mode, just input (mid-wavelength and FWHM of each wavelength )in the file of Meris_FWHM.txt
