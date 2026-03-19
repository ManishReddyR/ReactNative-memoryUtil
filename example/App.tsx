import React, { useCallback, useEffect, useState } from 'react'
import { Pressable, StyleSheet, Text, View } from 'react-native'
import { ReactNativeNitroMemoryUtil } from 'react-native-react-native-nitro-memory-util';

function App(): React.JSX.Element {
  const [processBytes, setProcessBytes] = useState<number>(0)
  const [totalBytes, setTotalBytes] = useState<number>(0)
  const [utilization, setUtilization] = useState<number>(0)
  const [error, setError] = useState<string | null>(null)

  const formatMB = (bytes: number): string => `${(bytes / (1024 * 1024)).toFixed(2)} MB`

  const refreshMemory = useCallback(() => {
    try {
      const [process, total, percent] = ReactNativeNitroMemoryUtil.getMemoryUtilization()
      setProcessBytes(process)
      setTotalBytes(total)
      setUtilization(percent)
      setError(null)
    } catch (e) {
      const message = e instanceof Error ? e.message : 'Failed to call Nitro module'
      setError(message)
    }
  }, [])

  useEffect(() => {
    refreshMemory()
  }, [refreshMemory])

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Nitro Memory Util Test</Text>
      <Text style={styles.row}>Process: {formatMB(processBytes)}</Text>
      <Text style={styles.row}>Total: {formatMB(totalBytes)}</Text>
      <Text style={styles.row}>Utilization: {utilization.toFixed(2)}%</Text>

      {error ? <Text style={styles.error}>Error: {error}</Text> : null}

      <Pressable style={styles.button} onPress={refreshMemory}>
        <Text style={styles.buttonText}>Refresh</Text>
      </Pressable>
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#101417',
    justifyContent: 'center',
    alignItems: 'center',
    paddingHorizontal: 20,
  },
  title: {
    fontSize: 28,
    color: '#E6F7FF',
    fontWeight: '700',
    marginBottom: 20,
  },
  row: {
    fontSize: 18,
    color: '#BCEBFF',
    marginBottom: 8,
  },
  button: {
    marginTop: 22,
    backgroundColor: '#00A3CC',
    paddingHorizontal: 18,
    paddingVertical: 10,
    borderRadius: 10,
  },
  buttonText: {
    color: '#00212A',
    fontSize: 16,
    fontWeight: '700',
  },
  error: {
    marginTop: 12,
    color: '#FF7E7E',
    textAlign: 'center',
  },
})

export default App;
