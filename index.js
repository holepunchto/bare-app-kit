require.asset = require('require-asset')

const prebuilds = {}

exports.prebuilds = prebuilds

prebuilds['darwin-x64'] = () => {
  return require.asset('./prebuilds/darwin-x64/bare', __filename)
}

prebuilds['darwin-arm64'] = () => {
  return require.asset('./prebuilds/darwin-arm64/bare', __filename)
}
